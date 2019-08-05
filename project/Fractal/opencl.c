/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:14:50 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/01 19:09:59 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	opencl_start(t_cl *cl)
{
	if ((cl->err = clGetPlatformIDs(1, &(cl->plat_id), 0)))	// второй запрос, заполняет массив требуемым количеством платформ
	{
		printf("Second platform request error: %u", (unsigned int)cl->err);
		return (0);
	}
	if ((cl->err = clGetDeviceIDs(cl->plat_id, CL_DEVICE_TYPE_GPU, 1, &(cl->dev_id), 0)))	// второй запрос, заполняет массив требуемым количеством устройств
	{
		printf("Second device request error: %u", (unsigned int)cl->err);
		return (0);
	}
	cl->cont = clCreateContext(0, 1, &(cl->dev_id), 0, 0, &(cl->err_int));
	if ((int)cl->err_int != 0)
	{
		printf("Failed to create content, error: %d", (int)cl->err_int);
		return (0);
	}
	if (!(cl->queue = clCreateCommandQueue(cl->cont, cl->dev_id, 0, &(cl->err_int))))	// создание очереди команд
	{																					// 1: контекст
		printf("Failed to create queue, error: %d", (int)cl->err_int);					// 2: устройства
		if ((cl->err_int = clReleaseContext(cl->cont)) == CL_INVALID_CONTEXT)			// 3: свойства очереди
			printf("Invalid context\n");												// 4: возможны ошибки
		return (0);
	}
	const char *src;
	int fd = open("mand.cl", O_RDONLY);
	src = (const char*)malloc(sizeof(const char) * 10000);
	size_t count;
	count = read(fd, (char*)src, 10000);
	cl->prog = clCreateProgramWithSource(cl->cont, 1, &src, &count, &(cl->err_int));		// создает програмный объект CL
	cl->err_int = clBuildProgram(cl->prog, 1, &(cl->dev_id), 0, 0, 0);									// компилирует програмный объект CL
	if (cl->err_int == CL_BUILD_PROGRAM_FAILURE)
		printf("err - %d\n", (int)cl->err_int);
	// cl->frac = clCreateBuffer(cl->cont, CL_MEM_READ_ONLY, sizeof(), 0, &(cl->err_int));			// выделяет память для аргумента
	// cl->kern = clCreateKernel(cl->prog, "rot13", &(cl->err_int));							// создает объект потока
	// cl->err_int = clSetKernelArg(cl->kern, 0, sizeof(mem1), &mem1);							// передает аргументы в функцию потока
	// cl->err_int = clEnqueueWriteBuffer(cl->queue, mem1, CL_FALSE, 0, len, buf, 0, 0, 0);	// запись данных в аргумент
	// cl->err_int = clEnqueueNDRangeKernel(cl->queue, cl->kern, 1, 0, &len, &len, 0, 0, 0);	// запуск потока
	// cl->err_int = clEnqueueReadBuffer(cl->queue, mem2, CL_FALSE, 0, len, buf2, 0, NULL, NULL);
	// // Ожидаем завершения всего вышеперечисленного
	// if ((int)(cl->err_int = clFinish(cl->queue)) != 0)	// завершение очереди, после выполнения всех действий
	// {
	// 	printf("Finish queue error: %d\n", (int)cl->err_int);
	// 	if ((cl->err_int = clReleaseContext(cl->cont)) == CL_INVALID_CONTEXT)
	// 		printf("Invalid context\n");
	// 	return (0);
	// }
	// if ((cl->err_int = clReleaseContext(cl->cont)) == CL_INVALID_CONTEXT)
	// 	printf("Invalid context\n");
	// printf("Happy - %s", buf2);
	return (0);
}
