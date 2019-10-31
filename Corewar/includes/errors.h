/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:00:52 by pibenoit          #+#    #+#             */
/*   Updated: 2017/02/11 19:00:53 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H

# define ERRORS_H

# include <op.h>

# define ERROR(error) ft_printf(error)

# define OPEN_ERROR(name) "For open(\"%s\"):\n%s\n", name, strerror(errno)
# define READ_ERROR(name) "While reading on %s:\n%s\n", name, strerror(errno)
# define WRITE_ERROR(name) "While writing on %s:\n%s\n", name, strerror(errno)
# define BAD_ASM_ERROR(name) "Bad asm file: %s\n", name
# define MISSING_ARGUMENT_ERROR "Need one file as argument\n"
# define NO_OP "No operation\n"

# define BAD_SECTION_ERROR "Missing required section\n"
# define TOO_MUCH_SECTION_ERROR "Too much section\n"
# define SECTION_FORMAT_ERROR(l) "Line %d: bad section format\n", l

# define UNKNOWN_COMMAND(l, name) "Line %d: unknown command %s\n", l, name
# define BAD_LABEL(l, c) "Line %d: Bad label character %c\n", l, c

# define NO_ARG(l, c, i) "Line %d, cmd %s: missing argument %d\n", l, c, i
# define BAD_REG(l, c, n) "Line %d, reg %s: %d -> bad reg number\n", l, c, n
# define BAD_ARG(l, arg) "Line %d: %s bad argument\n", l, arg
# define TRUNCATE_ARG(l, src, dst) "Line %d: %s truncated to %d\n", l, src, dst

# define CHP_SIZE(a) "Champion size is %zu and must be %d\n", a, CHAMP_MAX_SIZE

# define UNKNOWN_LABEL(label) "Unknown label %s\n", label

# define SIZE_ERROR "Not good number of bytes to write\n"

#endif
