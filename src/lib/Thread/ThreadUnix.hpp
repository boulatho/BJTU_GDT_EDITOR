#ifndef		THREADUNIX_HPP_
# define	THREADUNIX_HPP_

# include	<pthread.h>
# include	"IThread.hpp"

class		ThreadUnix : public IThread
{
public:

  ThreadUnix();
  virtual ~ThreadUnix();

  virtual bool	create(void*(*function)(void*), void* parameters);
  virtual bool	exit();
  virtual bool	wait();

  virtual int	getId() const;

private:

  pthread_t	_thread;
  int		_id;
};

#endif		// !THREADUNIX_HPP_
