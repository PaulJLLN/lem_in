/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:39:42 by pauljull          #+#    #+#             */
/*   Updated: 2020/02/06 13:35:15 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H

# define MACRO_H

# define ANTS				100000
# define PRIME				36131
# define ERR_BAD_DATA		-2
# define BASE_MALLOC 		8192
# define LINK				12

/*
	MACRO indispensable (Paul)
*/

# define BUFF_SIZE			4096
# define IGNORE				-1
# define EMPTY				3
# define OCCUPIED			4
# define NO_LINK			0
# define UNCHANGED			1
# define UNQUEUE			2
# define AUGMENTED			3
# define INFINY				4
# define BLOCKED			5
# define TO_CUT				6
# define QUEUE				9
# define IS_START			10
# define IS_END				11
# define VISITED			12
# define RESTRICT			13
/*
	Couleurs
*/

# define _RED				"\x1b[31m"
# define _GREEN				"\x1b[32m"
# define _YELLOW			"\x1b[33m"
# define _BLUE				"\x1b[34m"
# define _MAGENTA			"\x1b[35m"
# define _CYAN				"\x1b[36m"
# define _RESET				"\x1b[0m"

/*
	MACRO de debug
*/

# define COUCOU				printf("COUCOU\n")
#endif
