/**
 * SA-MP Socket Plugin (SSL-Free)
 * Version: v1.0.0
 * 
 * Originally developed by BlueG (c) 2012–2014
 * Modified and repackaged as an SSL-free version by the RJRYT.
 * 
 * Windows and Linux support (x86)
 * No OpenSSL dependency – lightweight and clean build.
 */

#if defined socket_included
	#endinput
#endif
#define socket_included

#define INVALID_SOCKET (-1)
#define INVALID_CLIENT_ID (-1)
#define NO_IP_RETURN "0.0.0.0"
#define INADDR_ANY NO_IP_RETURN

enum pType {
	TCP = 1,
	UDP = 2
};

native Socket:socket_create(pType:TCP); // udp & tcp
native socket_bind(Socket:id, ip[]); // udp & tcp
native socket_connect(Socket:id, host[], port); // udp & tcp
native socket_listen(Socket:id, port); // udp & tcp
native socket_stop_listen(Socket:id); // udp & tcp
native socket_destroy(Socket:id); // udp & tcp
native socket_send(Socket:id, data[], len); // udp & tcp
native socket_sendto(Socket:id, const ip[], port, data[], len);
native socket_send_array(Socket:id, data[], size=sizeof(data));
native is_socket_valid(Socket:id); // udp & tcp
native socket_set_max_connections(Socket:id, max_remote_clients); // tcp only
native socket_close_remote_client(Socket:id, remote_clientid); // tcp only
native socket_sendto_remote_client(Socket:id, remote_clientid, data[]); // tcp only
native socket_remote_client_connected(Socket:id, remote_clientid); // tcp only
native get_remote_client_ip(Socket:id, remote_clientid, ip[]); // tcp only


// client & server (udp)
forward onUDPReceiveData(Socket:id, data[], data_len, remote_client_ip[], remote_client_port);
// client only (tcp)
forward onSocketAnswer(Socket:id, data[], data_len); // called when socket_connect() has been used and the server sends data
forward onSocketClose(Socket:id);
// server only (tcp)
forward onSocketReceiveData(Socket:id, remote_clientid, data[], data_len); // called when a remote client sends data
forward onSocketRemoteConnect(Socket:id, remote_client[], remote_clientid); // called when a remote client connects to our socket server
forward onSocketRemoteDisconnect(Socket:id, remote_clientid); // called when a remote client disconnects from our socket server
