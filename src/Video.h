#pragma once

/*extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}*/
#include <string>

class Video
{
	Video(std::string filename, unsigned width, unsigned height);
}