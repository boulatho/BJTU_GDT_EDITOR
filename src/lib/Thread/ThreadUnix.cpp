#include	<pthread.h>
#include	"ThreadUnix.hpp"

ThreadUnix::ThreadUnix()
{

}

ThreadUnix::~ThreadUnix()
{

}

bool		ThreadUnix::create(void*(*function)(void*), void* parameters)
{
  if (pthread_create(&this->_thread, NULL, function, parameters) != 0)
    {
      return (false);
    }
  return (true);
}

bool		ThreadUnix::exit()
{
  pthread_exit(NULL);
  return (true);
}

bool		ThreadUnix::wait()
{
  if (pthread_join(this->_thread, NULL) != 0)
    {
      return (false);
    }
  return (true);
}

int		ThreadUnix::getId() const
{
  return (this->_id);
}
