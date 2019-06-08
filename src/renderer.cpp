#if 0
#include <ctime>
#include "Renderer.h"

Renderer::~Renderer()
{
  endwin();
}

Renderer::Renderer(Video video_stream) : 
buffer_(video_stream.getFrame()),
videoStream_(video_stream),
window_(initscr()),
render_time_(video_stream.getFrameStamp())
{}

void Renderer::render_frame()
{
  render_time_ = videoStream_.timestamp()); //set how long the frame needs to render for
  videoStream_.loadBuffer();

  std::clock_t time_req = std::clock(); //get current time
  render();
  render_time_ -= std::clock() - time_req; //subtract how long it took to load buffer
  time_req = std::clock();
  while (rendering(time_req));
}

void Renderer::render()
{
  //set color here
  waddch(window_, 219); //prints the [] thing
  refresh();
}

bool Renderer::rendering(std::clock_t start_time)
{
  return (render_time_ > std::clock() - start_time ? 1 : 0);
}
#endif
