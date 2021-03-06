#ifndef HEADER_22ED4A0273107176
#define HEADER_22ED4A0273107176

/***************************************************************************
 *   Author: El Andaluz														 *
 *                                                                         *
 ***************************************************************************/

#ifndef _IO_PROCESS_H
#define _IO_PROCESS_H

#include "linuxlist.h"

#define MAX_BUFFER_SIZE 1024

struct fd_obj {
	struct llist_head list;
	int32_t fd;
	u_int32_t iotype;	// of het om ontvangen of verzenden gaat
	int32_t (*fh)(struct fd_obj* fdo);
	void (*th)(void);	//th = timer handler
	struct sockaddr* psockaddr;
	char data[MAX_BUFFER_SIZE];
};

int32_t io_select();
struct fd_obj* add_fdo(int32_t fd);
void remove_fdo(int32_t fd);


#endif //_IO_PROCESS_H

#endif // header guard
