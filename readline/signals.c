/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:41:18 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/01 13:45:25 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

t_bool	g_is_interrupted;

static void	sigwinch_handler(int signum)
{
	(void)signum;
	update_win_dimensions();
}

static void	sigint_handler(int signum)
{
	(void)signum;
	ft_putstr("^C");
	goto_end();
	ft_putchar('\n');
	ioctl(0, TIOCSTI, "\0");
	g_is_interrupted = TRUE;
}

void	set_signal_handlers(sig_t *signals)
{
	signals[SIGINT_HANDLER] = signal(SIGINT, sigint_handler);
	signals[SIGWINCH_HANDLER] = signal(SIGWINCH, sigwinch_handler);
}

void	restore_signal_handlers(sig_t *signals)
{
	signal(SIGINT, signals[SIGINT_HANDLER]);
	signal(SIGWINCH, signals[SIGWINCH_HANDLER]);
}
