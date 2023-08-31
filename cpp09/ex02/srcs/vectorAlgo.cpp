/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAlgo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:14:24 by trobert           #+#    #+#             */
/*   Updated: 2023/04/06 19:16:36 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::vector<int> PmergeMe::insertSort(std::vector<int> arr)
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

std::vector<int> PmergeMe::mergeSort(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> arr;
	int i = 0;
	int j = 0;
	while (i < (int) left.size() && j < (int) right.size())
	{
		if (left[i] < right[j])
		{
			arr.push_back(left[i]);
			i++;
		}
		else
		{
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

std::vector<int> PmergeMe::hybridFordJohnsonSort(std::vector<int> arr)
{
	if (arr.size() <= 16)
		return insertSort(arr);
	else
	{
		int mid = arr.size() / 2;
		std::vector<int> left_half(arr.begin(), arr.begin() + mid);
		std::vector<int>  right_half(arr.begin() + mid, arr.end());
		left_half = hybridFordJohnsonSort(left_half);
		right_half = hybridFordJohnsonSort(right_half);
		return mergeSort(left_half, right_half);
	}
}