/* aws-greengrass-lite - AWS IoT Greengrass runtime for constrained devices
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GGL_CONSTANTS_H
#define GGL_CONSTANTS_H

/// The max depth of nested objects via maps or lists
#define GGL_MAX_OBJECT_DEPTH 15

/// The maximum expected config keys (including nested) held under one component
/// configuration
#define MAX_CONFIG_DESCENDANTS_PER_COMPONENT 256

/// The maximum expected config keys held as children of a single config object
#define MAX_CONFIG_CHILDREN_PER_OBJECT 64

// According to
// https://docs.aws.amazon.com/iot/latest/apireference/API_ThingAttribute.html
#define THING_NAME_MAX_LENGTH 128

#endif
