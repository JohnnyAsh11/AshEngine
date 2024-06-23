#pragma once

/// <summary>
/// Dictates how a Renderable object will behave.
/// </summary>
class IRender
{
protected:
	virtual void Render() = 0;
};

