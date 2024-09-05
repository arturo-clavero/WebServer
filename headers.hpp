/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:47:38 by artclave          #+#    #+#             */
/*   Updated: 2024/09/05 12:28:24 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_HPP
# define HEADERS_HPP

#include <unistd.h> //execve, dup, dup2, pipe, fork, close, read, write, access, chdir
#include <string.h> //strerror
#include <netdb.h> //gai_strerror , getaddrinfo, freeaddrinfo, getprotobyname
#include <errno.h> //errno
#include <arpa/inet.h> //htons, htonl, ntohs, ntohl
#include <sys/select.h> //select
#include <poll.h> //poll
#include <sys/epoll.h> //epoll_create, epoll_ctl, epoll_wait
#include <sys/socket.h> // socketpair, socket, accept, listen, send, recv, bind, connect, setsockopt, getsockname
#include <sys/event.h> //kqueue, kevent
#include <fcntl.h> //fcntl, open
#include <sys/wait.h> //waitpid
#include <signal.h> //kill, signal
#include <sys/stat.h> //stat
#include <dirent.h> //opendir, readdir, closedir
#include <map> //map struct in data struct draft

#endif