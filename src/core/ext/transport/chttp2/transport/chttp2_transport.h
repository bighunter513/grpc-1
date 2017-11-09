/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_CORE_EXT_TRANSPORT_CHTTP2_TRANSPORT_CHTTP2_TRANSPORT_H
#define GRPC_CORE_EXT_TRANSPORT_CHTTP2_TRANSPORT_CHTTP2_TRANSPORT_H

#include "src/core/lib/debug/trace.h"
#include "src/core/lib/iomgr/endpoint.h"
#include "src/core/lib/transport/transport.h"

#ifdef __cplusplus
extern "C" {
#endif

extern grpc_tracer_flag grpc_http_trace;
extern grpc_tracer_flag grpc_flowctl_trace;
extern grpc_tracer_flag grpc_trace_http2_stream_state;

#ifndef NDEBUG
extern grpc_tracer_flag grpc_trace_chttp2_refcount;
#endif

grpc_transport* grpc_create_chttp2_transport(
    grpc_exec_ctx* exec_ctx, const grpc_channel_args* channel_args,
    grpc_endpoint* ep, bool is_client);

/// Takes ownership of \a read_buffer, which (if non-NULL) contains
/// leftover bytes previously read from the endpoint (e.g., by handshakers).
/// If non-null, \a notify_on_receive_settings will be scheduled when
/// HTTP/2 settings are received from the peer.
void grpc_chttp2_transport_start_reading(
    grpc_exec_ctx* exec_ctx, grpc_transport* transport,
    grpc_slice_buffer* read_buffer, grpc_closure* notify_on_receive_settings);

#ifdef __cplusplus
}
#endif

#endif /* GRPC_CORE_EXT_TRANSPORT_CHTTP2_TRANSPORT_CHTTP2_TRANSPORT_H */
