#
# run with ./hello  --docroot . --http-address XX.YY.ZZ.WW --http-port KKKK
#
WT_INCLUDE_DIR = /usr/local/include
WT_LIB_DIR = /usr/local/lib

hello: hello.C FormWidgets.C  FormWidgets.h \
              ControlsWidget.C  EventDisplayer.C \
              ControlsWidget.h  EventDisplayer.h DeferredWidget.h ; \
  $(CXX) -o $@ hello.C FormWidgets.C ControlsWidget.C  EventDisplayer.C \
              -I. -I$(WT_INCLUDE_DIR) -L$(WT_LIB_DIR) \
                       -lwt -lwthttp -lboost_signals
