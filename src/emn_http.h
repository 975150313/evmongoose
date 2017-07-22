#ifndef __EMN_HTTP_H_
#define __EMN_HTTP_H_

#include <http_parser.h>
#include "emn.h"

#define EMN_FLAGS_HTTP				(1 << 0)

#define EMN_MAX_HTTP_HEADERS		40

/* HTTP and websocket events. void *ev_data is described in a comment. */
#define EMN_EV_HTTP_REQUEST	100	/* struct http_message * */
#define EMN_EV_HTTP_REPLY	101	/* struct http_message * */
#define EMN_EV_HTTP_CHUNK	102	/* struct http_message * */

struct http_opts {
	/* Path to web root directory */
	const char *document_root;

	/* List of index files. Default is "" */
	const char *index_files;
};

void emn_set_protocol_http(struct emn_server *srv, struct http_opts *opts);

enum http_method emn_get_http_method(struct emn_client *cli);
struct emn_str *emn_get_http_url(struct emn_client *cli);
struct emn_str *emn_get_http_path(struct emn_client *cli);
struct emn_str *emn_get_http_query(struct emn_client *cli);
uint8_t emn_get_http_version_major(struct emn_client *cli);
uint8_t emn_get_http_version_minor(struct emn_client *cli);
struct emn_str *emn_get_http_header(struct emn_client *cli, const char *name);
struct emn_str *emn_get_http_body(struct emn_client *cli);

#endif