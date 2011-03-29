/*
 * Xournal++
 *
 * Serializeable interface
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __SERIALIZEABLE_H__
#define __SERIALIZEABLE_H__

#include "../util/String.h"
#include <exception>

#define INPUT_STREAM_EXCEPTION(description, ...) \
	InputStreamException(String::format(description, __VA_ARGS__), __FILE__, __LINE__); \


class InputStreamException: public std::exception {
public:
	InputStreamException(String message, const char * filename, int line);
	virtual ~InputStreamException() throw ();

public:
	virtual const char* what() const throw ();

private:
	XOJ_TYPE_ATTRIB;

	String message;
};

class ObjectOutputStream;
class ObjectInputStream;

class Serializeable {
public:
	virtual void serialize(ObjectOutputStream & out) = 0;
	virtual void readSerialized(ObjectInputStream & in) throw (InputStreamException) = 0;
};

#endif /* __SERIALIZEABLE_H__ */