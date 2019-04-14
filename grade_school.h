#if !defined(grade_school_h)
#define grade_school_h

#include <map>
#include <string>
#include <vector>

namespace grade_school {
    using StudentList = std::vector<std::string>;
    using Roster = std::map<int, StudentList>;
    using KVP = std::pair<int, StudentList>;

    class school {
    private:
        Roster m_roster;

    public:
        const Roster roster();
        void add(const std::string student, const int grade);
        StudentList grade(const int grade) const;
    };

} // namespace grade_school

#endif
