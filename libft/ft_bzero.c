/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:26:54 by selow             #+#    #+#             */
/*   Updated: 2025/04/19 21:59:51 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
int	main(void)
{
	int	i;

	char arr[50] = "everything here";
	int nums[50] = {3, 4, 5, 6};

	// Calling the function on the arrays
	ft_bzero(&arr, 5);
	ft_bzero(&nums, sizeof(nums));

	// Array result : none due to null terminator
	printf("Array printf string: %s\n", arr);
	
	// Modified result : 
	printf("Modified arr content: ");
	for (int i = 0; i < sizeof(arr); i++)
		printf("%c", arr[i]);
	printf("\n");

	// Num result
	printf("Modified int array: ");
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
		printf("%d ", nums[i]);
	printf("\n");
	return 0;
}*/
