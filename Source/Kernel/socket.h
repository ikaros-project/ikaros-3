//
//	IKAROS_Socket.h		Socket utilities for the IKAROS project
//
//    Copyright (C) 2001-2011  Christian Balkenius
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//    See http://www.ikaros-project.org/ for more information.
//


#ifndef SOCKET
#define SOCKET

#include <stddef.h>

//#include "IKAROS_System.h"
#include "utilities.h"
#include "deprecated.h"

#define PORTNO		8000 	// the default port users will be connecting to



class SocketException
	{
	public:
		char	*		string;
		int			internal_reference;
		
		SocketException(char * s, int ref = 0) : string(s), internal_reference(ref)
		{};
	};



//
//	Socket used to request data from a HTTP server in a simple way
//

class SocketData;

class Socket
	{
	public:
		Socket();
		~Socket();
		
		std::string 	HTTPGet(const std::string & url);
		bool			Poll(); // return true if data is waiting
		void			Close();
		
		// Old functions
	
		bool			SendRequest(const char * hostname, int port, const char * request, const long size=-1);

		int				ReadData(char * result, int maxlen, bool fill=false);
		int				Get(const char * hostname, int port, const char * request, char * result, int maxlen);
	

		
	private:
		SocketData *		data;
	};



//
//	The class socket implements a simple HTTP server
//

class ServerSocketData;

class ServerSocket
	{
	public:
		ServerSocket(int port=PORTNO);		// Create server socket on port
		~ServerSocket();
		
		Dictionary			header;									// The current HTTP request header
		bool				GetRequest(bool block=false);           // Check for request and read if available
		
		bool				SendHTTPHeader(Dictionary * d = NULL, const char * response=NULL);
		bool				SendData(const char * buffer, long size);
		bool				Send(const char * format, ...); // Maximum 1023 characters
		bool				Send(std::string data);
		bool				Send(const float *, int sizex, int sizey);
		bool				SendFile(const char * filename, const char * path="", Dictionary * header = NULL); // FIXME: add header automatically based on file type
		bool				SendFile(const std::string & filename, const std::string & path="");
		void				fillBuffer(std::string s);
		bool				SendBuffer();
		void 				clearBuffer();

		bool				Close();								// Close reply socket
		
		int					Port();									// Get port no
		const char *		Host();									// Get host name
		
		int					errcode;								// Last error
	private:
		ServerSocketData *	data;
		
		bool				Poll(bool block=false);                 // Poll for connection; return >=0 if accepted connection (or > 0 CHECK!!!)
		long				Read(char * buffer, int maxSize);		// Read
		std::string 		buffer;	
	};


#endif

