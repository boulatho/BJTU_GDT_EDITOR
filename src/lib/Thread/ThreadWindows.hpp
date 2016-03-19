#ifndef		THREADWINDOWS_HPP_
# define	THREADWINDOWS_HPP_

# include	<Windows.h>
# include	"IThread.hpp"

class		ThreadWindows : public IThread
{
public:

  ThreadWindows();
  virtual ~ThreadWindows();

  virtual bool	create(void*(*function)(void*), void* parameters);
  virtual bool	exit();
  virtual bool	wait();

  virtual int	getId() const;

private:

  HANDLE	_thread;
  DWORD		_id;
};

#endif		// !THREADWINDOWS_HPP_
