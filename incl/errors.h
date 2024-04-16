/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:45:43 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/11 11:15:15 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "colors.h"

# define DUP_P "Map content is not valid! \
Map contains more than 1"B_P" player."DEF
# define DUP_E	"Map content is not valid! \
Map contains more than 1"B_O" exit."DEF
# define DUP_P_E	"Map content is not valid! \
Map contains"B_P" player"DEF" and"B_O" exit"B_B" duplicates."DEF
# define DUP_NO_C	"Map content is not valid! \
Map contains"B_B" duplicates"DEF " and no"B_G" collectables."DEF
# define NO_P "Map content is not valid! We're missing a"B_P" player."DEF
# define NO_E "Map content is not valid! There is no"B_O" exit."DEF
# define NO_C "Map content is not valid! \
No"B_G" collectables"DEF" available."

#endif