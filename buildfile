cxx.std = latest
using cxx

hxx{*}: extension = hpp
cxx{*}: extension = cpp
exe{*}: test = true

exe{morton}: {hxx cxx}{**}
