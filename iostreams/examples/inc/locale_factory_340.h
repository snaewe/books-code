/*
author:  "Klaus Wittlich" <Klaus_Wittlich@sae.de> 

Based on source code published in the book "Standard C++ IOStreams 
and Locales" by Angelika Langer & Klaus Kreft, Copyright (c) 2000 by 
Addison Wesley Longman, Inc.

Permission to use, copy, and modify this software for any non-profit
purpose is hereby granted without fee.  Neither the author of this 
source code, Klaus Wittlich, nor the authors of the above mentioned 
book, Angelika Langer and Klaus Kreft, nor the publisher, Addison
Wesley Longman, Inc., make any representations about the suitability of this 
software for any purpose.  It is provided "as is" without express or 
implied warranty.
*/

/*
#include locale_factory_340.h
*/

#ifndef LOCALE_FACTORY_H
#define LOCALE_FACTORY_H

// p. 340 {{{
class locale_factory
{
public:
    virtual locale make_locale (const char * name) const
    {
        return locale(name);
    }
};
// }}}

// p. 341 {{{
class address_locale_factory : public locale_factory
{
    typedef ostreambuf_iterator<char, char_traits<char> > osIter;

public:
    address_locale_factory()
    {
        facets["US"] = new US_address_put<char, osIter>(1); // !!! En_US changed to US, otherwise program crash
        facets["German"] = new German_address_put<char, osIter>(1); // !!! De_DE changed to German, otherwise program crash
    }

    ~address_locale_factory()
    {
        delete facets["US"]; // !!! En_US changed to US, otherwise program crash
        delete facets["German"]; // !!! De_DE changed to German, otherwise program crash
    }

    locale make_locale (const char* name) const
    {
        if (facets.find(name) == facets.end() )
            return locale_factory::make_locale(name);
        else
            return locale(locale_factory::make_locale(name),
            (*(facets.find(name))).second);
    }

private:
    map<string, address_put<char, osIter>*> facets;
};
// }}}

#endif
