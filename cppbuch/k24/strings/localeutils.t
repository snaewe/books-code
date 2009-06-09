/* cppbuch/k24/strings/localeutils.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<locale>
#include<string>
#include<cstring>
#include<iostream>

template<typename charT>
void klein(std::basic_string<charT>& s, 
           const std::locale& loc = std::locale()) {
   for(size_t i = 0; i < s.length(); ++i) {
      s[i] = std::use_facet<std::ctype<charT> >(loc).tolower(s[i]);
   }
}

template<typename charT>
void gross(std::basic_string<charT>& s, 
           const std::locale& loc = std::locale()) {
   for(size_t i = 0; i < s.length(); ++i) {
      s[i] = std::use_facet<std::ctype<charT> >(loc).toupper(s[i]);
   }
}

template<typename charT>
struct Stringvergleich {
   Stringvergleich(const std::locale& lo = std::locale()) 
      : loc(lo) {
   }
   bool operator()(const std::basic_string<charT>& s1, 
                   const std::basic_string<charT>& s2) {
      return std::use_facet<std::collate<charT> >(loc)
         .compare(s1.c_str(), s1.c_str() + s1.length(), 
                  s2.c_str(), s2.c_str() + s2.length()) < 0;
   }
   const std::locale loc;
};


template<typename charT>
inline bool equalIgnoreCase(charT c1, charT c2,
                       const std::locale& loc = std::locale()) {
   return std::use_facet<std::ctype<charT> >(loc).toupper(c1)
      == std::use_facet<std::ctype<charT> >(loc).toupper(c2);
}

template<typename charT>
struct EqualIgnoreCase {
   EqualIgnoreCase(const std::locale& lo = std::locale()) 
      : loc(lo) {
   }
   bool operator()(charT c1, charT c2) {
      return equalIgnoreCase(c1, c2, loc);
   }
   const std::locale loc;
};


