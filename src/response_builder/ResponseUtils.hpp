/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseUtils.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:40:51 by bperez-a          #+#    #+#             */
/*   Updated: 2024/09/11 09:51:45 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_UTILS_HPP
#define RESPONSE_UTILS_HPP

#include "includes.hpp"
#include "RequestResponse.hpp"
#include "../request_parser/HttpRequest.hpp"
#include "../config/ServerConfig.hpp"


enum FileType {
	IS_FILE,
	IS_DIRECTORY,
	NOT_FOUND
};

class ResponseUtils {
public:
	static bool isRequestValid(const HttpRequest& request);
	static LocationConfig findLocation(const std::string& path, const ServerConfig& config);
	static bool isMethodAllowed(const HttpRequest& request, const LocationConfig& location);
	static std::string buildBodyFromFile(const ServerConfig& config, const std::string& path);
	static FileType getTargetType(const HttpRequest& request);
	static bool shouldForceDownload(const std::string& extension);
	static std::string getContentType(const std::string& path);	
	static std::string getContentDisposition(const std::string& path);
	
private:
    ResponseUtils();
};

#endif
