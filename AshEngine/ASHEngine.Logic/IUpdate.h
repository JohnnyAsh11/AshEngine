#pragma once

/// <summary>
/// Dictates how a Updatable object will behave.
/// </summary>
class IUpdate
{
protected:
	virtual void Update() = 0;
};

