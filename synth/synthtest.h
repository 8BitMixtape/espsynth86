#ifndef SYNTHTEST_H
#define SYNTHTEST_H
#include "Synth.h"
#include "ModuleConstant.h"
#include "ModuleWavetableOsc.h"
#include "ModuleLowpassFilter.h"
#include "ModuleMixer2.h"
#include "ModuleLFO.h"

class SynthTest : public Synth
{
public:
    ModuleConstant param[8];

    SynthTest()
    {
        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBkcXFkIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGRxcWQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA5MXd2
        IGVzcG5vZGUvbXVsdGlwbGV4ZXIgTXVsdGlwbGV4ZXIKbm9kZS90dXJuLW9uIDkxd3YKbm9kZS9hZGQtb3V0bGV0IDkxd3YgNjlnbSBlc3Bub2RlL3N0cmluZyBQb3QxIFBvdDEKbm9kZS9hZGQtb3V0bGV0IDkxd3YgMjk5ZSBlc3Bub2RlL3N0cmluZyBQb3QyIFBv
        dDIKbm9kZS9hZGQtb3V0bGV0IDkxd3YgOHU5dCBlc3Bub2RlL3N0cmluZyBQb3QzIFBvdDMKbm9kZS9hZGQtb3V0bGV0IDkxd3YgamdhcSBlc3Bub2RlL3N0cmluZyBQb3Q0IFBvdDQKbm9kZS9hZGQtb3V0bGV0IDkxd3YgbGI0MyBlc3Bub2RlL3N0cmluZyBQb3Q1
        IFBvdDUKbm9kZS9hZGQtb3V0bGV0IDkxd3Ygdng2cSBlc3Bub2RlL3N0cmluZyBQb3Q2IFBvdDYKbm9kZS9hZGQtb3V0bGV0IDkxd3YgZ21odyBlc3Bub2RlL3N0cmluZyBQb3Q3IFBvdDcKbm9kZS9hZGQtb3V0bGV0IDkxd3YgaG41cCBlc3Bub2RlL3N0cmluZyBQ
        b3Q4IFBvdDgKcGF0Y2gvYWRkLW5vZGUgc2FkNCBkd2E2IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiBkd2E2Cm5vZGUvYWRkLWlubGV0IGR3YTYgbHhvNyBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lu
        cHV0Cm5vZGUvYWRkLWlubGV0IGR3YTYgeHVwOSBlc3Bub2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCBkd2E2IDhrNHcgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGtvdnYg
        ZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIGtvdnYKbm9kZS9hZGQtaW5sZXQga292diAzdXIxIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgdGcxOSBlc3Bub2RlL29zY2lsbGF0b3Ig
        T3NjaWxsYXRvcgpub2RlL3R1cm4tb24gdGcxOQpub2RlL2FkZC1pbmxldCB0ZzE5IHI5cDggZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCB0ZzE5IGE0Z2sgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxl
        X2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgdGcxOSBvNHQ0IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCByd2c0IGVzcG5vZGUvbWl4ZXIyIDIlMjBDaCUyME1peGVyCm5vZGUvdHVybi1vbiByd2c0Cm5vZGUv
        YWRkLWlubGV0IHJ3ZzQgM3FjNSBlc3Bub2RlL3N0cmluZyBjaDEgY2gxCm5vZGUvYWRkLWlubGV0IHJ3ZzQgZmFndiBlc3Bub2RlL3N0cmluZyBjaDIgY2gyCm5vZGUvYWRkLW91dGxldCByd2c0IDMwdDEgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApub2RlL21vdmUg
        ZHFxZCAzMCAyMApub2RlL21vdmUgOTF3diA1NjEgMTAxCm5vZGUvbW92ZSBkd2E2IDczOCAxMDMKbm9kZS9tb3ZlIGtvdnYgMTI2MiAyNDYKbm9kZS9tb3ZlIHRnMTkgNzkxIDIzMwpub2RlL21vdmUgcndnNCAxMDM2IDE0OQpvdXRsZXQvY29ubmVjdCA2OWdtIGx4
        bzcgeHozcgpvdXRsZXQvY29ubmVjdCAyOTllIHh1cDkgcmhxcwpvdXRsZXQvY29ubmVjdCA4azR3IDNxYzUgdHNudApvdXRsZXQvY29ubmVjdCBvNHQ0IGZhZ3YgdW4yYQpvdXRsZXQvY29ubmVjdCAzMHQxIDN1cjEgcW14OApvdXRsZXQvY29ubmVjdCAyOTllIGE0
        Z2sgcGV6cwpvdXRsZXQvY29ubmVjdCA4dTl0IHI5cDggOTg2bwpub2RlL3VwZGF0ZS1pbmxldCBkd2E2IGx4bzcgZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgZHdhNiB4dXA5IHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHRn
        MTkgYTRnayB3YXZldGFibGVfaW5wdXQgMA==
        --ENDESPNODEPATCH--

        */



        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();


        moduleWavetableOsc_1->frequency_input= &param[0];
        moduleWavetableOsc_1->wavetable_input= &param[1];
        moduleMixer2_1->ch1=moduleWavetableOsc_1;
        moduleMixer2_1->ch2=moduleWavetableOsc_2;
        moduleWavetableOsc_2->wavetable_input= &param[1];
        moduleWavetableOsc_2->frequency_input= &param[2];


        this->last_module = moduleMixer2_1;


        // end of espnode86 generated code //


}
};
#endif // SYNTHTEST_H
