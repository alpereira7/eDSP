//
// Created by Mohammed Boujemaoui on 11/10/2017.
//

#ifndef EDSP_GENERATOR_H
#define EDSP_GENERATOR_H

#include "math/container.h"
#include "base/algoritmtemplate.h"

EDSP_BEGING_NAMESPACE
    namespace generators {
        template<typename T>
        class Generator : public AlgorithmTemplate {
        public:
            EDSP_DISABLE_DEFAULT(Generator)
            EDSP_DISABLE_COPY(Generator)
            explicit Generator(size_t size, T sampleRate = 0, T frequency = 0, T phase = 0, T amplitude = 1) :
                                                                             sampleRate(sampleRate),
                                                                             frequency(frequency),
                                                                             amplitude(amplitude),
                                                                             data(std::vector<T>(size)),
                                                                             AlgorithmTemplate(true, Error())
            {
                Math::Container::set(data, static_cast<T>(0));
            }
            ~Generator() override = default;

            virtual inline size_t getSize() const {  return data.size(); }
            virtual void setSize(size_t size) {
                if (size != data.size()) {
                    data.resize(size);
                    Math::Container::set(data, static_cast<T>(0));
                }
            }

            virtual inline T getSampleRate() const { return sampleRate; }
            virtual void setSampleRate(T sampleRate) {
                Generator::sampleRate = sampleRate;
            }

            virtual inline T getFrequency() const { return frequency; }
            virtual void setFrequency(T frequency) {
                Generator::frequency = frequency;
            }

            virtual inline T getAmplitude() const {  return amplitude; }
            virtual void setAmplitude(T amplitude) {
                Generator::amplitude = amplitude;
            }

        protected:
            T sampleRate{0};
            T frequency{0};
            T amplitude{1};
            std::vector<T> data;
        };

}

EDSP_END_NAMESPACE


#endif //EDSP_GENERATOR_H
