#ifndef _QUICKVIEW_RELOADER_WRAPPER_H__
#define _QUICKVIEW_RELOADER_WRAPPER_H__

#include "QuickViewReloader.h"

class QuickViewReloaderWrapper : public QuickViewReloader
{
public:
    QuickViewReloaderWrapper();
    ~QuickViewReloaderWrapper();
private:
    virtual void setContextProperies( QQmlContext * pQmlContext );
    virtual void registerToQml();
    void Clear();
};


#endif//_QUICKVIEW_RELOADER_WRAPPER_H__
