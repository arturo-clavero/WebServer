/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestParser.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:56:07 by bperez-a          #+#    #+#             */
/*   Updated: 2024/09/11 10:53:16 by bperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_PARSER_HPP
#define REQUEST_PARSER_HPP

#include "includes.hpp"
#include "HttpRequest.hpp"

class RequestParser {
public:
    static HttpRequest parse(const std::string& request_str);
	static std::string trimAndSanitize(const std::string& str);

private:
    RequestParser() {}
};

#endif
