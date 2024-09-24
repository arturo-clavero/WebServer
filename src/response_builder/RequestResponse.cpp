/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestResponse.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:17:15 by bperez-a          #+#    #+#             */
/*   Updated: 2024/09/25 05:49:44 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestResponse.hpp"

RequestResponse::RequestResponse() {
}

RequestResponse::~RequestResponse() {
}

std::string RequestResponse::getBody() const { return this->body; }
std::string RequestResponse::getStatusCode() const { return this->statusCode; }
std::string RequestResponse::getStatusMessage() const { return this->statusMessage; }
std::string RequestResponse::getContentType() const { return this->contentType; }
size_t RequestResponse::getContentLength() const { return this->contentLength; }
std::string RequestResponse::getContentDisposition() const { return this->contentDisposition; }
std::string RequestResponse::getFilePathForBody() const { return this->file_path_for_body; }
const std::vector<int> RequestResponse::getPostFileFds() const { return postFileFds; }
const std::vector<std::string> RequestResponse::getPostFileContents() const { return postFileContents;}


void RequestResponse::setBody(const std::string& body) { this->body = body; }
void RequestResponse::setStatusCode(const std::string& statusCode) { this->statusCode = statusCode; }
void RequestResponse::setStatusMessage(const std::string& statusMessage) { this->statusMessage = statusMessage; }
void RequestResponse::setContentType(const std::string& contentType) { this->contentType = contentType; }
void RequestResponse::setContentLength(size_t contentLength) { this->contentLength = contentLength; }
void RequestResponse::setContentDisposition(const std::string& contentDisposition) { this->contentDisposition = contentDisposition; }
void RequestResponse::setFilePathForBody(const std::string& file_path_for_body) { this->file_path_for_body = file_path_for_body; }
void RequestResponse::setPostFileContents(const std::vector<std::string> & contents) {postFileContents = contents; }
void RequestResponse::setPostFileFds(const std::vector<int> & fds) {postFileFds = fds;}
	
void RequestResponse::popBackPostFileContents() {postFileContents.pop_back();}
void RequestResponse::popBackPostFileFds() {postFileFds.pop_back();}

std::string RequestResponse::toString() const {
	std::string response;	
	response += "HTTP/1.1 " + this->statusCode + " " + this->statusMessage + "\r\n";
	response += "Content-Type: " + this->contentType + "\r\n";
	
	std::stringstream ss;
	ss << this->contentLength;
	std::string contentLengthStr = ss.str();
	
	response += "Content-Length: " + contentLengthStr + "\r\n";
	if (!this->contentDisposition.empty())
		response += "Content-Disposition: " + this->contentDisposition + "\r\n";
	response += "\r\n";
	response += this->body;
	return response;
}

void RequestResponse::setContentLengthFromPath(const std::string& path) {
	std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);
	if (file.is_open()) {
		file.seekg(0, std::ios::end);
		this->contentLength = file.tellg();
		file.close();
	}
}

bool RequestResponse::buildBodyFromFile(const ServerConfig& config, int file_fd) {
	(void)config;
	std::string	buff(READ_BUFFER_SIZE, 0);
	int bytes = read(file_fd, &buff[0], READ_BUFFER_SIZE);
	for (int i = 0; i < bytes; i++)
		this->body += buff[i];
//	if (bytes < 0)
//		what to do heere?
	if (bytes < READ_BUFFER_SIZE)
	{
		//READING COMPLETE
		return true;		
	}
	return false;
}




std::ostream& operator<<(std::ostream& os, const RequestResponse& requestResponse) {
	//prints everything but the body
	os << "HTTP/1.1 " << requestResponse.getStatusCode() << " " << requestResponse.getStatusMessage() << "\r\n";
	os << "Content-Type: " << requestResponse.getContentType() << "\r\n";
	os << "Content-Length: " << requestResponse.getContentLength() << "\r\n";
	os << "Content-Disposition: " << requestResponse.getContentDisposition() << "\r\n";
	
	os << "\r\n";
	return os;
}
