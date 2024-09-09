/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseBuilder.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:15:00 by bperez-a          #+#    #+#             */
/*   Updated: 2024/09/09 12:17:21 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_BUILDER_HPP
#define RESPONSE_BUILDER_HPP

#include "includes.hpp"
#include "../request_parser/HttpRequest.hpp"
#include "../config/ServerConfig.hpp"
#include "RequestResponse.hpp"

class ResponseBuilder {
public:

    static RequestResponse build(HttpRequest& request, ServerConfig& config);
	
	static RequestResponse buildGetResponse(ServerConfig& config, HttpRequest& request, LocationConfig& location);
	static RequestResponse buildGetFileResponse(ServerConfig& config, HttpRequest& request, LocationConfig& location);
	static RequestResponse buildGetDirectoryResponse(ServerConfig& config, HttpRequest& request, LocationConfig& location);

	static RequestResponse buildPostResponse(ServerConfig& config, HttpRequest& request, LocationConfig& location);
	//...
	
	static RequestResponse buildDeleteResponse(ServerConfig& config, HttpRequest& request, LocationConfig& location);
	//...

	static RequestResponse buildErrorResponse(ServerConfig& config, HttpRequest& request, const std::string& code, const std::string& message);
	static RequestResponse buildSuccessResponse(ServerConfig& config, HttpRequest& request, LocationConfig& location, std::string& path);
	static RequestResponse buildAutoindexResponse(ServerConfig& config, HttpRequest& request, LocationConfig& location, std::string& path);


private:
    ResponseBuilder() {}
};

#endif

