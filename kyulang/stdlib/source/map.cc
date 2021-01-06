#include "map.hh"

DEFINE_STDFUNC(kyu::lang::stdlib::map::newMap)
{
    auto map = new ast::KMap();

    if (args.size() % 2 != 0)
    {
        return new ast::KNil();
    }

    for (size_t i = 0; i + 1 < args.size(); i += 2)
    {
        auto key = reinterpret_cast<ast::KString*>(vm->EvaluateValue(args[i]));

        if (key->GetType() != ast::KValueType::String)
        {
            return new ast::KNil();
        }

        auto val = vm->EvaluateValue(args[i + 1]);
        map->Set(key->GetValue(), val);
    }

    return map;
}

DEFINE_STDFUNC(kyu::lang::stdlib::map::mapSet)
{
    auto map = reinterpret_cast<ast::KMap*>(vm->EvaluateValue(args[0]));

    if (args.size() < 3)
    {
        return new ast::KNil();
    }

    if ((args.size() - 1) % 2 != 0)
    {
        return new ast::KNil();
    }

    for (size_t i = 1; i + 1 < args.size(); i += 2)
    {
        auto key = reinterpret_cast<ast::KString*>(vm->EvaluateValue(args[i]));

        if (key->GetType() != ast::KValueType::String)
        {
            return new ast::KNil();
        }

        auto val = vm->EvaluateValue(args[i + 1]);
        map->Set(key->GetValue(), val);
    }

    return map;
}

DEFINE_STDFUNC(kyu::lang::stdlib::map::mapKeys)
{
    if (args.size() != 1)
    {
        return new ast::KNil();
    }

    auto map = reinterpret_cast<ast::KMap*>(vm->EvaluateValue(args[0]));

    if (map->GetType() != ast::KValueType::Map)
    {
        return new ast::KNil();
    }

    std::vector<ast::KValue*> list;

    for (const auto& key : map->GetKeys())
    {
        list.emplace_back(new ast::KString(key));
    }

    return new ast::KList(list);
}