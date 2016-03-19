#ifndef		ITHREAD_HPP_
# define	ITHREAD_HPP_

class		IThread
{
 public:

  virtual ~IThread() {}

  virtual bool	create(void*(*function)(void*), void* parameters) = 0;
  virtual bool	wait() = 0;
  virtual bool	exit() = 0;

  virtual int	getId() const = 0;
};

#endif		// !ITHREAD_HPP_

