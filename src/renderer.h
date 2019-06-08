#pragma once

#if 0

#ifdef _WIN32
#include <wincurses/wincurses.h>
#include "../lib/wincurses/wincurses.h"
#endif
//TODO:: Add linux support

#include <vector>
//#include "Video.h"

class Video;

struct Resolution
{
  unsigned width;
  unsigned height;
};
class Renderer
{
public:
  ~Renderer();
  Renderer(Video video_stream);
  Renderer(const Renderer& other) = delete;
  void render_frame();
  std::vector<char> *get_buffer();
private:
  bool Renderer::rendering(std::clock_t start_time);
  void render();
  std::vector<char> buffer_;
  Video& videoStream_;
  WINDOW *window_;
  float render_time_;
};

#endif