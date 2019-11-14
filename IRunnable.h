#pragma once

class IRunnable
{
public:
	virtual void Run()=0;
	virtual ~IRunnable() = default;
};

