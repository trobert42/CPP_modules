/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeAlgo.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:13:47 by trobert           #+#    #+#             */
/*   Updated: 2023/04/06 19:16:42 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::deque<int> PmergeMe::insertSort(std::deque<int> arr)
{
	int j = 1;
	while (j < (int) arr.size())
	{
		int i = j - 1;
		int carry = arr[j];
		while (i >= 0 && arr[i] > carry)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = carry;
		j++;
	}
	return arr;
}

std::deque<int> PmergeMe::mergeSort(std::deque<int> left, std::deque<int> right)
{
	std::deque<int> arr;
	int i = 0;
	int j = 0;
	while (i < (int) left.size() && j < (int) right.size())
	{
		if (left[i] < right[j])
		{
			arr.push_back(left[i]);
			i++;
		}
		else {
			arr.push_back(right[j]);
			j++;
		}
	}
	while (i < (int) left.size())
	{
		arr.push_back(left[i]);
		i++;
	}
	while (j < (int) right.size())
	{
		arr.push_back(right[j]);
		j++;
	}
	return arr;
}

std::deque<int> PmergeMe::hybridFordJohnsonSort(std::deque<int> arr)
{
	if (arr.size() <= 16)
		return insertSort(arr);
	else
	{
		int mid = arr.size() / 2;
		std::deque<int> left_half(arr.begin(), arr.begin() + mid);
		std::deque<int>  right_half(arr.begin() + mid, arr.end());
		left_half = hybridFordJohnsonSort(left_half);
		right_half = hybridFordJohnsonSort(right_half);
		return mergeSort(left_half, right_half);
	}
}
