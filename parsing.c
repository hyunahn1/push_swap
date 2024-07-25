/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:32:04 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/13 17:49:59 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_val(t_program main.stack_a, argv[i])
{
	
int	*parsing_stack(int argc, char **argv, t_program main)
{
	int	arr_size;

	arr_size = 0;
	if (argc == 2)
		argv = ft_split(argc[1], ' ');
	if (argc == 2)
		arr_size = -1;
	if (argc > 1)
	{
		while (argv[++arr_size])
		{
			if (!ft_check_val(main.stack_a, argv[arr_size]))
				ft_error(1);
			main.stack_a = add_data(main.stack_a, ft_atoi(argv[arr_size]));
		}
	}
	return (0);
}
