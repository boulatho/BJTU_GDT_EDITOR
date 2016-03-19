#include	"ThreadWindows.hpp"

ThreadWindows::ThreadWindows()
{

}

ThreadWindows::~ThreadWindows()
{

}

bool		ThreadWindows::create(void*(*function)(void*), void* parameters)
{
  if ((this->_thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)function, parameters, 0, &this->_id)) == NULL)
    {
      return (false);
    }
  return (true);
}

bool		ThreadWindows::exit()
{
  if (TerminateThread(this->_thread, NULL) == 0)
    {
      return (false);
    }
  return (true);
}

bool		ThreadWindows::wait()
{
  if (WaitForSingleObject(this->_thread, INFINITE) == WAIT_FAILED)
    {
      return (false);
    }
  return (true);
}

int		ThreadWindows::getId() const
{
  return (this->_id);
}
