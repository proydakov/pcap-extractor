#include <string>
#include <fstream>

#include <glib.h>
#include <config.h>
#include <epan/packet_info.h>
#include <epan/tap.h>
#include <epan/dissectors/packet-http.h>

extern const char version[] = "0.0.0";

static std::ofstream gfs("/tmp/decoded.txt", std::ofstream::trunc);

static void tap_reset(void*)
{
    //gfs << "Reset" << std::endl;
}

static gboolean tap_packet(void* ud, packet_info* info, epan_dissect_t* epan, const void* data)
{
    const http_eo_t& eo = *reinterpret_cast<const http_eo_t*>(data);
    //gfs << "Packet " << eo.hostname << eo.filename << ' ' << eo.content_type << std::endl;
    if (eo.content_type == std::string("application/json"))
    {
        gfs << std::string(reinterpret_cast<const char*>(eo.payload_data), eo.payload_len);
        gfs << std::endl << std::endl;
    }
    return true;
}

static void tap_draw(void*)
{
    //gfs << "Draw" << std::endl;
}

extern "C" void plugin_register_tap_listener()
{
    register_tap_listener("http_eo", &gfs, nullptr, 0, tap_reset, tap_packet, tap_draw);
}
