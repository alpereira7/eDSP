//
// Created by Mohammed Boujemaoui on 13/10/2017.
//

#ifndef EDSP_ZEROCROSSINGRATE_H
#define EDSP_ZEROCROSSINGRATE_H

#include "base/algoritmtemplate.h"

EDSP_BEGING_NAMESPACE
    namespace properties {
        template<typename T>
        class ZeroCrossingRate : public AlgorithmTemplate {
        public:
            explicit ZeroCrossingRate(bool normalized = true);
            ~ZeroCrossingRate() override = default;
            inline T compute(const std::vector<T>& data) const;
            inline bool isNormalized() const { return norm; }
            void normalize(bool state) { ZeroCrossingRate::norm = state; }
        private:
            bool norm{false};
        };
    }
EDSP_END_NAMESPACE
#endif //EDSP_ZEROCROSSINGRATE_H
