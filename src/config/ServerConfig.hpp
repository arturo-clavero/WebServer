/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:38:57 by bperez-a          #+#    #+#             */
/*   Updated: 2024/09/09 11:16:26 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CONFIG_HPP
#define SERVER_CONFIG_HPP

#include "includes.hpp"

struct LocationConfig {
    std::string path;
    std::string root;
    bool autoindex;
    std::vector<std::string> allowMethods;
    std::string index;
    std::string return_url;
    std::string alias;
};

struct CGIConfig {
    std::string root;
    std::string path;
    std::string ext;
};

class ServerConfig {
public:
	// Orthodox Canonical Form
    ServerConfig();
    ServerConfig(const ServerConfig& other);
    ServerConfig& operator=(const ServerConfig& other);
    ~ServerConfig();

    // Getters
    int getListen() const;
    const std::string& getHost() const;
    const std::string& getServerName() const;
    const std::map<std::string, std::string>& getErrorPages() const;
    size_t getClientMaxBodySize() const;
    const std::string& getRoot() const;
    const std::string& getIndex() const;
    std::vector<LocationConfig>& getLocations();
    const std::vector<LocationConfig>& getLocations() const;
    const CGIConfig& getCgi() const;
	int getListenSocket() const;
	const struct sockaddr_in& getAddress() const;
    // Setters
    void setListen(int value);
    void setHost(const std::string& value);
    void setServerName(const std::string& value);
    void setErrorPages(const std::map<std::string, std::string>& value);
    void setClientMaxBodySize(size_t value);
    void setRoot(const std::string& value);
    void setIndex(const std::string& value);
    void setLocations(const std::vector<LocationConfig>& value);
    void setCgi(const CGIConfig& value);
	void setListenSocket(int value);
	void setAddress(const struct sockaddr_in& value);
	// Debug
	void print() const;

private:
    int listen;
    std::string host;
    std::string serverName;
    std::map<std::string, std::string> errorPages;
    size_t clientMaxBodySize;
    std::string root;
    std::string index;
    std::vector<LocationConfig> locations;
    CGIConfig cgi;
	int listen_socket;
	struct sockaddr_in address;	
};

#endif
