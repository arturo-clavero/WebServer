/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestResponse.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:16:00 by bperez-a          #+#    #+#             */
/*   Updated: 2024/09/12 22:16:47 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_RESPONSE_HPP
#define REQUEST_RESPONSE_HPP

#include "includes.hpp"


class RequestResponse {
public:
    RequestResponse();
    ~RequestResponse();

	//Getters
	std::string getBody() const;
	std::string getStatusCode() const;
	std::string getStatusMessage() const;
	std::string getContentType() const;	
	std::string getContentDisposition() const;
	size_t getContentLength() const;

	//Setters
	void setBody(const std::string& body);
	void setStatusCode(const std::string& statusCode);
	void setStatusMessage(const std::string& statusMessage);
	void setContentType(const std::string& contentType);
	void setContentLength(size_t contentLength);
	void setContentDisposition(const std::string& contentDisposition);
	
    std::string toString() const;

private:
	std::string body;
	std::string statusCode;
	std::string statusMessage;
	std::string contentType;
	std::string contentDisposition;
	size_t contentLength;

};

std::ostream& operator<<(std::ostream& os, const RequestResponse& requestResponse);

#endif
