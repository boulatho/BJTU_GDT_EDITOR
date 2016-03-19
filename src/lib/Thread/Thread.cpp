#include	<iostream>
#include	"Thread.hpp"

#ifdef		WIN32
#include	"ThreadWindows.hpp"
#else
#include	"ThreadUnix.hpp"
#endif		// WIN32

Thread::Thread()
{
#ifdef WIN32
  this->_thread = new ThreadWindows;
#else
  this->_thread = new ThreadUnix;
#endif // WIN
}

Thread::~Thread()
{

}

bool		Thread::create(void*(*function)(void*), void* parameters)
{
  if (this->_thread->create(function, parameters) == false)
    {
      std::cerr << "[ERROR] : IThread::create failed." << std::endl;
      return (false);
    }
  return (true);
}

bool		Thread::exit()
{
  if (this->_thread->exit() == false)
    {
      std::cerr << "[ERROR] : IThread::exit failed." << std::endl;
      return (false);
    }
  return (true);
}

bool		Thread::wait()
{
  if (this->_thread->wait() == false)
    {
      std::cerr << "[ERROR] : IThread::wait failed." << std::endl;
      return (false);
    }
  return (true);
}

int		Thread::getId() const
{
  return (this->_thread->getId());
}
