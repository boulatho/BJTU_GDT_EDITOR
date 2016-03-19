#ifndef		THREAD_HPP_
# define	THREAD_HPP_

# include	"IThread.hpp"

class		Thread
{
public:

  Thread();
  ~Thread();

  bool		create(void*(*function)(void*), void* parameters);
  bool		exit();
  bool		wait();

  int		getId() const;

private:

  IThread*	_thread;
};

#endif		// !THREAD_HPP_
