/* Autogenerated with Kurento Idl */

#include <memory>

#include "MediaPipeline.hpp"
#include "Composite.hpp"
#include <JsonSerializer.hpp>

namespace kurento {

std::shared_ptr<MediaObject> Composite::Factory::createObject (const Json::Value &params)
{
  std::shared_ptr<MediaPipeline> mediaPipeline;
  int garbagePeriod = 0;

  if (!params.isMember ("mediaPipeline")) {
    /* param 'mediaPipeline' not present, raise exception */
    JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'mediaPipeline' parameter is requiered");
    throw e;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(mediaPipeline);
  }

  if (!params.isMember ("garbagePeriod")) {
    /* param 'garbagePeriod' not present, using default */
    garbagePeriod = 120;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(garbagePeriod);
  }

  return createObject (mediaPipeline, garbagePeriod);
}

Composite::Factory::StaticConstructor Composite::Factory::staticConstructor;

Composite::Factory::StaticConstructor::StaticConstructor()
{
  if (objectRegistrar) {
    std::shared_ptr <Factory> factory (new Composite::Factory());

    objectRegistrar->registerFactory(factory);
  }
}

void
Composite::Invoker::invoke (std::shared_ptr<MediaObject> obj,
    const std::string &methodName, const Json::Value &params,
    Json::Value &response)
{
  Hub::Invoker::invoke(obj, methodName, params, response);
}

std::string
Composite::connect(const std::string &eventType, std::shared_ptr<EventHandler> handler)
{
  return Hub::connect (eventType, handler);
}

} /* kurento */

void
Serialize(std::shared_ptr<kurento::Composite> &object, JsonSerializer &serializer)
{
  if (!serializer.IsWriter) {
    try {
      std::shared_ptr<kurento::MediaObject> aux;
      aux = kurento::Composite::Factory::getObject (serializer.JsonValue.asString ());
      object = std::dynamic_pointer_cast<kurento::Composite> (aux);
      return;
    } catch (kurento::JsonRpc::CallException &ex) {
      kurento::JsonRpc::CallException e (kurento::JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'Composite' object not found: "+ ex.getMessage());
      throw e;
    }
  }
  std::shared_ptr<kurento::Hub> aux = std::dynamic_pointer_cast<kurento::Hub> (object);

  void Serialize(std::shared_ptr<kurento::Hub> &object, JsonSerializer &serializer);
  Serialize(aux, serializer);
}

void
Serialize(kurento::Composite &object, JsonSerializer &serializer)
{
  void Serialize(kurento::Hub &object, JsonSerializer &serializer);
  try {
    Serialize(dynamic_cast<kurento::Hub &> (object), serializer);
  } catch (std::bad_cast) {
  }
}
