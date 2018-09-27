#pragma once

#include <optional>
#include <unordered_map>

#include "../AudioBackend.h"
#include "../PersistentParameters.h"

class AxiomVstPlugin;

class VstAudioBackend : public AxiomBackend::AudioBackend {
public:
    ssize_t midiInputPortal = 0;
    AxiomBackend::NumParameters audioInputs;
    AxiomBackend::NumParameters audioOutputs;
    AxiomBackend::NumParameters automationInputs;

    explicit VstAudioBackend(AxiomVstPlugin *plugin);

    void handleConfigurationChange(const AxiomBackend::AudioConfiguration &configuration) override;

    bool doesSaveInternally() const override { return true; }

    void automationValueChanged(size_t portalId, AxiomBackend::NumValue value) override;

    bool canFiddleAutomation() const override { return true; }

private:
    AxiomVstPlugin *plugin;
};
