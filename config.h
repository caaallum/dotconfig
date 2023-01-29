/*
 * This file is part of dotconfig.
 *
 * dotconfig is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dotconfig is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dotconfig.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2023 callum speirs
 * https://github.com/caaallum/dotconfig
 */

#ifndef __CONFIG_H
#define __CONFIG_H

int config_install(const char *path);

int config_uninstall(void);

#endif /* __CONFIG_H */
