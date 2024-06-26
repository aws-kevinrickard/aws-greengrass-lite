/* aws-greengrass-lite - AWS IoT Greengrass runtime for constrained devices
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GGL_COMMS_CLIENT_H
#define GGL_COMMS_CLIENT_H

/*! Pluggable RPC client interface */

#include "alloc.h"
#include "object.h"

typedef struct GglConn GglConn;

/** Open a connection to server on `path`. */
int ggl_connect(GglBuffer path, GglConn **conn)
    __attribute__((warn_unused_result));

/** Close a connection to a server. */
void ggl_close(GglConn *conn);

/** Make an RPC call.
 * `result` will use memory from `alloc` if needed. */
int ggl_call(
    GglConn *conn,
    GglBuffer method,
    GglList params,
    GglAlloc *alloc,
    GglObject *result
) __attribute__((warn_unused_result));

/** Make an RPC notification (no response). */
int ggl_notify(GglConn *conn, GglBuffer method, GglList params);

#endif