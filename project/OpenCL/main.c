/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:14:50 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/01 18:45:48 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"
#include <stdlib.h>

void rot13 (char *buf)
{
int index=0;
char c=buf[index];
while (c!=0) {
if (c<'A' || c>'z' || (c>'Z' && c<'a')) {
buf[index] = buf[index];
} else {
if (c>'m' || (c>'M' && c<'a')) {
buf[index] = buf[index]-13;
} else {
buf[index] = buf[index]+13;
}
}
c=buf[++index];
}
}

int	main()
{
	cl_uint				err;		// код ошибки
	cl_int				err_int;
	cl_platform_id		plat_id;	// идентификаторы платформы
	cl_uint				plat_count;	// количество платформ
	cl_device_id		dev_id;	// идентификаторы устройств
	cl_uint				dev_count;	// количество устройств
	cl_context			cont;
	cl_command_queue	queue;
	cl_program			prog;
	cl_kernel			kern;
	cl_mem				mem1;
	cl_mem				mem2;

	char buf[]="Hello, World!";
	size_t len = strlen(buf);
	rot13(buf);
	printf("1 - %s\n", buf);

	if ((err = clGetPlatformIDs(0, 0, &plat_count)))					// первый запрос, определяет количество платформ
	{																	// 1: количество платформ которые будут использоваться
		printf("First platform request error: %u", (unsigned int)err);	// 2: идентификаторы платформ
		return (0);														// 3: количество обнаруженных платформ
	}
	// printf("%u", (unsigned int)plat_count);
	if ((err = clGetPlatformIDs(plat_count, &plat_id, 0)))	// второй запрос, заполняет массив требуемым количеством платформ
	{
		printf("Second platform request error: %u", (unsigned int)err);
		return (0);
	}
	// if ((err = platform_information(&plat_id, plat_count)))	// вывод информации о платформах
	// {
	// 	printf("Request for information on platforms error: %u", (unsigned int)err);
	// 	free(plat_id);
	// 	return (0);
	// }
	if ((err = clGetDeviceIDs(plat_id, CL_DEVICE_TYPE_GPU, 0, NULL, &dev_count)))	// первый запрос, определяет количество устройств на платвформе
	{																				// 1: платформа
		printf("First device request error: %u", (unsigned int)err);				// 2: тип устройств
		return (0);																	// 3: количество устройств для использования
		}																			// 4: идентификаторы устройств
																					// 5: количество обнаруженных устройств
	// printf("%u", (unsigned int)dev_count);
	if ((err = clGetDeviceIDs(plat_id, CL_DEVICE_TYPE_GPU, dev_count, &dev_id, 0)))	// второй запрос, заполняет массив требуемым количеством устройств
	{
		printf("Second device request error: %u", (unsigned int)err);
		return (0);
	}
	// if ((err = device_information(&dev_id, dev_count)))	// вывод информации об устройствах
	// {
	// 	printf("Request information about devices error: %u", (unsigned int)err);
	// 	return (0);
	// }
	cont = clCreateContext(0, 1, &dev_id, 0, 0, &err_int);	// 1: массив свойств ообъекта
	// printf("err: %d", (int)err_int);						// 2: количество устройств
															// 3: указатель на устройства
															// 4: функция обратного вызова
															// 5: пользовательские данные (если требуются для вызванной функции)
															// 6: возможные ошибки
	if ((int)err_int != 0)
	{
		printf("Failed to create content, error: %d", (int)err_int);
		return (0);
	}
	// err_int = clReleaseContext(cont);
	// if (err_int == CL_INVALID_CONTEXT)
	// 		printf("Invalid context\n");
	if (!(queue = clCreateCommandQueue(cont, dev_id, 0, &err_int)))			// создание очереди команд
	{																		// 1: контекст
		printf("Failed to create queue, error: %d", (int)err_int);			// 2: устройства
		if ((err_int = clReleaseContext(cont)) == CL_INVALID_CONTEXT)		// 3: свойства очереди
			printf("Invalid context\n");									// 4: возможны ошибки
		return (0);
	}
	const char *src;
	int fd = open("rot13.cl", O_RDONLY);
	src = (const char*)malloc(sizeof(const char) * 10000);
	size_t count;
	count = read(fd, (char*)src, 10000);
	prog = clCreateProgramWithSource(cont, 1, &src, &count, &err_int);	// создает програмный объект CL
																		// 1: контекст
																		// 2: количество строк с кодом
																		// 3: указатель содержащий строки
																		// 4: указатель содержащий размеры строк
																		// 5: возможны ошибки
	err_int = clBuildProgram(prog, 0, 0, 0, 0, 0);	// компилирует програмный объект CL
													// 1: програмный объект CL
													// 2: количество устройств
													// 3: указатель содержащий используемые устройства
													// 4: параметры командной строки и линкера
													// 5: функция для вызова после компиляции (принимает текущие 1 и 6 параметры)
													// 6: пользовательские данные
	mem1 = clCreateBuffer(cont, CL_MEM_READ_ONLY, len, 0, &err_int);	// выделяет память для аргумента
																				// 1: контекст
																				// 2: флаг для работы с памятью
																				// 3: требуемый размер в байтах
																				// 4: данные уже выделенные приложением
																				// 5: возможные ошибки
	mem2 = clCreateBuffer(cont, CL_MEM_WRITE_ONLY, len, 0, &err_int);
	kern = clCreateKernel(prog, "rot13", &err_int);	// создает объект потока
													// 1: Програмный объект CL(скомпилированный)
													// 2: имя функции __kernel
													// 3: возможные ошибки
	err_int = clSetKernelArg(kern, 0, sizeof(mem1), &mem1);	// передает аргументы в функцию потока
															// 1: объект потока
															// 2: индекс аргумента потока
															// 3: размер данных
															// 4: передаваемый аргумент
	err_int = clSetKernelArg(kern, 1, sizeof(mem2), &mem2);
	err_int = clEnqueueWriteBuffer(queue, mem1, CL_FALSE, 0, len, buf, 0, 0, 0);	// запись данных в аргумент
																							// 1: очередь команд
																							// 2: заполняемый аргумент
																							// 3: способ осуществления действия, true/false произойдет ли возврат функции до завершения действия
																							// 4: индекс в памяти с которого идет запись в аргумент
																							// 5: количество записываемых байтов
																							// 6: аргумент для записи
																							// 7: количество событий для выхода ?????
																							// 8: указатель на события до выполнения которых возврата функции не будет ?????
																							// 9: указатель на итог события ?????
	err_int = clEnqueueNDRangeKernel(queue, kern, 1, 0, &len, &len, 0, 0, 0);	// запуск потока
																				// 1: очередь команд
																				// 2: объект потока
																				// 3: количество глобальных рабочих элементов (1-3)
																				// 4: (в будущем) смещение для вычисления глобального рабочего элемента.
																				// 5:
																				// 6:
																				// 7:
																				// 8:
																				// 9:
	char buf2[sizeof buf];
	buf2[0]='?';
	buf2[len]=0;
	err_int = clEnqueueReadBuffer(queue, mem2, CL_FALSE, 0, len, buf2, 0, NULL, NULL);
	// Ожидаем завершения всего вышеперечисленного
	if ((int)(err_int = clFinish(queue)) != 0)	// завершение очереди, после выполнения всех действий
	{
		printf("Finish queue error: %d\n", (int)err_int);
		if ((err_int = clReleaseContext(cont)) == CL_INVALID_CONTEXT)
			printf("Invalid context\n");
		return (0);
	}
	if ((err_int = clReleaseContext(cont)) == CL_INVALID_CONTEXT)
		printf("Invalid context\n");
	printf("Happy - %s", buf2);
	return (0);
}
