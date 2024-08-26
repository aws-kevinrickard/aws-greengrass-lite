// aws-greengrass-lite - AWS IoT Greengrass runtime for constrained devices
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#ifndef PROVISIONER_H
#define PROVISIONER_H

#include <sys/types.h>
#include <ggl/bump_alloc.h>
#include <ggl/error.h>
#include <ggl/object.h>
#include <openssl/types.h>
#include <openssl/x509.h>

GglError make_request(
    char *csr_as_string, char *cert_file_path, pid_t iotcored_pid
);

#endif