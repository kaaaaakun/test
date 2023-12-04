/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test15-gettimeofday.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:35:30 by tokazaki          #+#    #+#             */
/*   Updated: 2023/10/20 15:07:02 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
		long long int	ms;
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    // 秒単位の時間
    time_t seconds = currentTime.tv_sec;
    // マイクロ秒単位の時間
    suseconds_t microseconds = currentTime.tv_usec;

		// ミリ秒の生成
		ms = seconds * 1000 + microseconds / 1000;
    printf("現在の時刻: %ld , %d ミリ秒\n", seconds, microseconds);
    printf("	msでの現在の時刻: %lld\n", ms);

    return (0);
}
