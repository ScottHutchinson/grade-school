#include "grade_school.h"
#include <algorithm>

namespace grade_school {

    const Roster grade_school::school::roster() {
        std::for_each(m_roster.begin(), m_roster.end(),
            [](auto& kvp) { std::sort(kvp.second.begin(), kvp.second.end()); }
        );

        return m_roster;
    }

    void school::add(const std::string student, const int grade) {
        if (m_roster.find(grade) == m_roster.end()) { // grade not found
            m_roster.insert(KVP(grade, StudentList{}));
        }
        m_roster.at(grade).push_back(student);
    }

    StudentList school::grade(const int grade) const {
        if (m_roster.find(grade) == m_roster.end()) { // grade not found
            return StudentList{};
        }
        auto students = m_roster.at(grade);
        std::sort(students.begin(), students.end());
        return students;
    }

} // namespace grade_school
