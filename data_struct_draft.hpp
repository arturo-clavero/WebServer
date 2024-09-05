/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct_draft.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:10:23 by artclave          #+#    #+#             */
/*   Updated: 2024/09/05 12:31:44 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.hpp"

//SHARED DATA STRUCTURES

//1. Communication between networking and http protocol:
typedef struct data{
	const void	*data_rcv; //raw data recieved ny network from client for http to interpret
	//size_t	rcv_size; //maybe not necessary...
	const void	*data_sent; //data sent from http protocol, for network to send to client, formatted appropriately
	//size_t	sent_size; //maybe not necessary ...
	int			socket_fd; //fd of socket that has received the data and will send it
};

#define GET 0
#define POST 1
#define DELETE 2

//2. Parsing and http protocol:
typedef struct http{
	int method;// "GET", "POST", "DELETE" defines
    std::string uri; // The requested resource
    std::string http_version; // e.g., "HTTP/1.1", is this needed since we are asked to assume it will always be 1.1?
	std::map<std::string, std::string> headers;
	std::string	body;
	size_t body_length;
	//const std::string buffer;//buffer containing either the input (recieved) to be parsed, or the output of the string to be sent ... maybe not necessary
};

//3. Finally we need a struct for config file both for network and http protocol to reference
typedef struct config{
	//
};