# `gg_config` interface

The `gg_config` core-bus interface provides functionality for managing the
Greengrass installation's configuration. The configuration follows JSON
structure.

Each method in the interface is described below.

## read

The `read` method returns the value associated with `key_path`. If the key has
subkeys, the value is an object with the key-value pairs under the key, which
are read recursively.

- [gg-config-read-1] `read` can be invoked with call.
- [gg-config-read-2] `read` on an object key returns an object encoding the
  hierarchy under that key.

### Parameters

- [gg-config-read-params-1] `key_path` is a required parameter of type list.
  - [gg-config-read-params-1.1] list elements are buffers containing a single
    level in the key hierarchy.

### Response

- [gg-config-read-resp-1] The response value is the value that was stored in the
  database for the key.
- [gg-config-read-resp-2] The method will error if a response value is not
  provided.
  - [gg-config-read-resp-2.1] `GG_ERR_NOENTRY` will be returned if the key was
    not in the configuration.

## write

The `write` method updates the value associated with `key_path`. If the `value`
is an object with subkeys, it is merged in recursively. Any values (i.e. leaves
of the `value` object) are updated if the new timestamp is greater or equal to
an existing value's timestamp.

- [gg-config-write-1] `write` can be invoked with call or notify.

### Parameters

- [gg-config-write-params-1] `key_path` is a required parameter of type list.
  - [gg-config-write-params-1.1] list elements are buffers containing a single
    level in the key hierarchy.
- [gg-config-write-params-2] `value` is a required parameter of type object.
  - [gg-config-write-params-2.1] `value` will be used to recursively update the
    config at `key_path`.
- [gg-config-write-params-3] `timestamp` is an optional parameter of type int.
  - [gg-config-write-params-3.1] `timestamp` is the Unix epoch time in ms to use
    to compare against existing values.
  - [gg-config-write-params-3.2] If the value is older than an existing key it
    would overwrite, then the old value is kept instead.
  - [gg-config-write-params-3.3] If not provided, the current time is used.

### Response

The `write` method does not have a response value.

- [gg-config-write-resp-1] If the method returns without an error, the
  configuration has been successfully updated.

## delete

The `delete` method removes the key and value associated with `key_path`, if
present. If the value is a map with subkeys, everything under it is also deleted
recursively. If the key does not exist, nothing happens.

- [gg-config-delete-1] `delete` can be invoked with call or notify.

### Parameters

- [gg-config-delete-params-1] `key_path` is a required parameter of type list.
  - [gg-config-delete-params-1.1] list elements are buffers containing a single
    level in the key hierarchy.

### Response

The `delete` method does not have a response value.

- [gg-config-delete-resp-1] If the method returns without an error, the
  configuration key does not exist, either because it was deleted or it didn't
  exist when the call was made.

## subscribe

The `subscribe` method sets up a subscription to updates to the value associated
with `key_path`.

- [gg-config-subscribe-1] `subscribe` can be invoked with call.

### Parameters

- [gg-config-subscribe-params-1] `key_path` is a required parameter of type
  list.
  - [gg-config-subscribe-params-1.1] list elements are buffers containing a
    single level in the key hierarchy.

### Response

- [gg-config-subscribe-resp-1] Subscription responses are sent on each update.
  - [gg-config-subscribe-resp-1.1] The response value is the key path which was
    updated. This may be a child of the `key_path` parameter.
- [gg-config-subscribe-resp-1] The method will return an error if the
  subscripion is not set up.
